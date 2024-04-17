/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bproc.c
 *
 */

/* Processes */

#include "bproc.h"
#include "osbs.inl"
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__UNIX__)
#error This file is for Unix/Unix-like system
#endif

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>

#define STDIN_READ_CHILD 0
#define STDIN_WRITE_PARENT 1
#define STDOUT_READ_PARENT 2
#define STDOUT_WRITE_CHILD 3
#define STDERR_READ_PARENT 4
#define STDERR_WRITE_CHILD 5

#if defined __LINUX__
int kill(pid_t pid, int sig);
#endif

struct _process_t
{
    int pipes[6];
    pid_t pid;
};

/*----------------------------------------------------------------------------*/

static Proc *i_create(int *pipes, pid_t pid)
{
    Proc *proc = (Proc *)bmem_malloc(sizeof(Proc));
    _osbs_proc_alloc();
    bmem_copy_n(proc->pipes, pipes, 6, int);
    proc->pid = pid;
    return proc;
}

/*---------------------------------------------------------------------------*/

static void i_close_pipes(int *pipes)
{
    register uint32_t i;
    cassert_no_null(pipes);
    for (i = 0; i < 6; ++i)
    {
        if (pipes[i] >= 0)
            close(pipes[i]);
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_pipes(int pipes[6])
{
    pipes[0] = -1;
    pipes[1] = -1;
    pipes[2] = -1;
    pipes[3] = -1;
    pipes[4] = -1;
    pipes[5] = -1;

    if (pipe(pipes) == -1)
    {
        i_close_pipes(pipes);
        return FALSE;
    }

    if (pipe(pipes + 2) == -1)
    {
        i_close_pipes(pipes);
        return FALSE;
    }

    if (pipe(pipes + 4) == -1)
    {
        i_close_pipes(pipes);
        return FALSE;
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_exec(const char_t *command, int *pipes, pid_t *pid)
{
    cassert_no_null(pipes);
    cassert_no_null(pid);
    *pid = fork();
    if (*pid == -1)
    {
        return FALSE;
    }
    /* Child */
    else if (*pid == 0)
    {
        dup2(pipes[STDIN_READ_CHILD], STDIN_FILENO);
        close(pipes[STDIN_READ_CHILD]);
        close(pipes[STDIN_WRITE_PARENT]);

        dup2(pipes[STDOUT_WRITE_CHILD], STDOUT_FILENO);
        close(pipes[STDOUT_WRITE_CHILD]);
        close(pipes[STDOUT_READ_PARENT]);

        dup2(pipes[STDERR_WRITE_CHILD], STDERR_FILENO);
        close(pipes[STDERR_WRITE_CHILD]);
        close(pipes[STDERR_READ_PARENT]);

        execlp("bash", "bash", "-c", command, NULL);
        cassert_msg(FALSE, "It's a zombie!");
        return FALSE;
    }
    /* Parent */
    else
    {
        close(pipes[STDIN_READ_CHILD]);
        close(pipes[STDOUT_WRITE_CHILD]);
        close(pipes[STDERR_WRITE_CHILD]);
        pipes[STDIN_READ_CHILD] = -1;
        pipes[STDOUT_WRITE_CHILD] = -1;
        pipes[STDERR_WRITE_CHILD] = -1;

        /* Avoid parent process end when is block in a bproc_write with full pipe */

        /*If all file descriptors referring to the read end of a pipe have been closed,
         * then a write(2) will cause a SIGPIPE signal to be generated for the calling
         * process. If the calling process is ignoring this signal, then write(2) fails
         * with the error EPIPE */
        signal(SIGPIPE, SIG_IGN);
        return TRUE;
    }
}

/*---------------------------------------------------------------------------*/

Proc *bproc_exec(const char_t *command, perror_t *error)
{
    int pipes[6];
    pid_t pid;

    if (i_pipes(pipes) == FALSE)
    {
        ptr_assign(error, ekPPIPE);
        return NULL;
    }

    if (i_exec(command, pipes, &pid) == FALSE)
    {
        i_close_pipes(pipes);
        ptr_assign(error, ekPEXEC);
        return NULL;
    }

    return i_create(pipes, pid);
}

/*---------------------------------------------------------------------------*/

/*
   On Unix and Unix-like computer operating systems, a zombie process
   or defunct process is a process that has completed execution but still
   has an entry in the process table. This entry is still needed to allow
   the parent process to read its child's exit status.

   Processes marked <defunct> are dead processes (so-called "zombies") that
   remain because their parent has not destroyed them properly.

   If the parent process calls waitpid and child has finished, the child will
   be deleted from ps -A and will not appers like <defunc>
 */

void bproc_close(Proc **proc)
{
    cassert_no_null(proc);
    cassert_no_null(*proc);
    i_close_pipes((*proc)->pipes);
    waitpid((*proc)->pid, NULL, WNOHANG);
    _osbs_proc_dealloc();
    bmem_free((byte_t *)*proc);
    *proc = NULL;
}

/*---------------------------------------------------------------------------*/

bool_t bproc_cancel(Proc *proc)
{
    cassert_no_null(proc);
    if (kill(proc->pid, SIGKILL) == 0)
        return TRUE;
    else
        return FALSE;
}

/*---------------------------------------------------------------------------*/

uint32_t bproc_wait(Proc *proc)
{
    int status;
    cassert_no_null(proc);
    if (waitpid(proc->pid, &status, 0) != -1)
    {
        return WEXITSTATUS(status);
    }
    else
    {
        return UINT32_MAX;
    }
}

/*---------------------------------------------------------------------------*/

bool_t bproc_finish(Proc *proc, uint32_t *code)
{
    int ret, status;
    int err;
    cassert_no_null(proc);
    ret = waitpid(proc->pid, &status, WNOHANG);
    if (ret == proc->pid)
    {
        ptr_assign(code, (uint32_t)WEXITSTATUS(status));
        return TRUE;
    }
    else if (ret == 0)
    {
        return FALSE;
    }
    else if (ret == -1)
    {
        if ((err = errno) == ECHILD)
        {
            ptr_assign(code, (uint32_t)WEXITSTATUS(status));
            return TRUE;
        }
    }

    cassert(FALSE);
    return TRUE;
}

/*---------------------------------------------------------------------------*/

/* If a process attempts to read from an empty pipe, then read(2) will
   block until data is available.  If a process attempts to write to a
   full pipe (see below), then write(2) blocks until sufficient data has
   been read from the pipe to allow the write to complete. Nonblocking
   I/O is possible by using the fcntl(2) F_SETFL operation to enable the
   O_NONBLOCK open file status flag.

   The communication channel provided by a pipe is a byte stream: there
   is no concept of message boundaries.

   If all file descriptors referring to the write end of a pipe have
   been closed, then an attempt to read(2) from the pipe will see end-
   of-file (read(2) will return 0). If all file descriptors referring
   to the read end of a pipe have been closed, then a write(2) will
   cause a SIGPIPE signal to be generated for the calling process. If
   the calling process is ignoring this signal, then write(2) fails with
   the error EPIPE.
*/
bool_t bproc_read(Proc *proc, byte_t *data, const uint32_t size, uint32_t *rsize, perror_t *error)
{
    ssize_t lrsize;
    cassert_no_null(proc);
    lrsize = read(proc->pipes[STDOUT_READ_PARENT], (char *)data, (unsigned)size);
    if (lrsize > 0)
    {
        ptr_assign(rsize, (uint32_t)lrsize);
        ptr_assign(error, ekPOK);
        return TRUE;
    }
    else if (lrsize == 0)
    {
        ptr_assign(rsize, 0);
        ptr_assign(error, ekPOK);
        return FALSE;
    }
    else
    {
        ptr_assign(rsize, 0);
        ptr_assign(error, ekPPIPE);
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t bproc_eread(Proc *proc, byte_t *data, const uint32_t size, uint32_t *rsize, perror_t *error)
{
    ssize_t lrsize;
    cassert_no_null(proc);
    lrsize = read(proc->pipes[STDERR_READ_PARENT], (char *)data, (unsigned)size);
    if (lrsize > 0)
    {
        ptr_assign(rsize, (uint32_t)lrsize);
        ptr_assign(error, ekPOK);
        return TRUE;
    }
    else if (lrsize == 0)
    {
        ptr_assign(rsize, 0);
        ptr_assign(error, ekPOK);
        return FALSE;
    }
    else
    {
        ptr_assign(rsize, 0);
        ptr_assign(error, ekPPIPE);
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t bproc_write(Proc *proc, const byte_t *data, const uint32_t size, uint32_t *wsize, perror_t *error)
{
    ssize_t lwsize;
    cassert_no_null(proc);
    lwsize = write(proc->pipes[STDIN_WRITE_PARENT], (const char *)data, (unsigned)size);
    if (lwsize >= 0)
    {
        ptr_assign(wsize, (uint32_t)lwsize);
        ptr_assign(error, ekPOK);
        return TRUE;
    }
    else
    {
        ptr_assign(wsize, 0);
        if (errno == EPIPE)
        {
            ptr_assign(error, ekPOK);
        }
        else
        {
            ptr_assign(error, ekPPIPE);
        }
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t bproc_read_close(Proc *proc)
{
    cassert_no_null(proc);
    if (proc->pipes[STDOUT_READ_PARENT] != -1)
    {
        close(proc->pipes[STDOUT_READ_PARENT]);
        proc->pipes[STDOUT_READ_PARENT] = -1;
        return TRUE;
    }
    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t bproc_eread_close(Proc *proc)
{
    cassert_no_null(proc);
    if (proc->pipes[STDERR_READ_PARENT] != -1)
    {
        close(proc->pipes[STDERR_READ_PARENT]);
        proc->pipes[STDERR_READ_PARENT] = -1;
        return TRUE;
    }
    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t bproc_write_close(Proc *proc)
{
    cassert_no_null(proc);
    if (proc->pipes[STDIN_WRITE_PARENT] != -1)
    {
        close(proc->pipes[STDIN_WRITE_PARENT]);
        proc->pipes[STDIN_WRITE_PARENT] = -1;
        return TRUE;
    }
    return FALSE;
}

/*---------------------------------------------------------------------------*/

void bproc_exit(const uint32_t code)
{
    exit((int)code);
}
