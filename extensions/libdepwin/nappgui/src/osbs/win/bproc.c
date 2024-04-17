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

#include "osbs.inl"
#include "bproc.h"
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is for Windows system
#endif

#include <sewer/nowarn.hxx>
#include <Windows.h>
#include <sewer/warn.hxx>

#define STDIN_READ_CHILD 0
#define STDIN_WRITE_PARENT 1
#define STDOUT_READ_PARENT 2
#define STDOUT_WRITE_CHILD 3
#define STDERR_READ_PARENT 4
#define STDERR_WRITE_CHILD 5

struct _process_t
{
    HANDLE pipes[6];
    PROCESS_INFORMATION info;
};

/*---------------------------------------------------------------------------*/

static Proc *i_create(HANDLE *pipes, PROCESS_INFORMATION *info)
{
    Proc *proc = (Proc *)bmem_malloc(sizeof(Proc));
    _osbs_proc_alloc();
    bmem_copy_n(proc->pipes, pipes, 6, HANDLE);
    proc->info = *info;
    return proc;
}

/*---------------------------------------------------------------------------*/

static void i_close_pipes(HANDLE *pipes)
{
    register uint32_t i;
    cassert_no_null(pipes);
    for (i = 0; i < 6; ++i)
    {
        if (pipes[i] != NULL)
            CloseHandle(pipes[i]);
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_pipes(HANDLE *pipes)
{
    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;
    bmem_zero_n(pipes, 6, HANDLE);

    if (!CreatePipe(&pipes[STDIN_READ_CHILD], &pipes[STDIN_WRITE_PARENT], &saAttr, 0))
    {
        i_close_pipes(pipes);
        return FALSE;
    }

    if (!SetHandleInformation(pipes[STDIN_WRITE_PARENT], HANDLE_FLAG_INHERIT, 0))
    {
        i_close_pipes(pipes);
        return FALSE;
    }

    if (!CreatePipe(&pipes[STDOUT_READ_PARENT], &pipes[STDOUT_WRITE_CHILD], &saAttr, 0))
    {
        i_close_pipes(pipes);
        return FALSE;
    }

    if (!SetHandleInformation(pipes[STDOUT_READ_PARENT], HANDLE_FLAG_INHERIT, 0))
    {
        i_close_pipes(pipes);
        return FALSE;
    }

    if (!CreatePipe(&pipes[STDERR_READ_PARENT], &pipes[STDERR_WRITE_CHILD], &saAttr, 0))
    {
        i_close_pipes(pipes);
        return FALSE;
    }

    if (!SetHandleInformation(pipes[STDERR_READ_PARENT], HANDLE_FLAG_INHERIT, 0))
    {
        i_close_pipes(pipes);
        return FALSE;
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_exec(const char_t *command, HANDLE *pipes, PROCESS_INFORMATION *info)
{
    WCHAR commandw[1024] = L"cmd /c ";
    STARTUPINFO stinfo;
    uint32_t size;
    cassert_no_null(pipes);
    cassert_no_null(info);
    ZeroMemory(&stinfo, sizeof(STARTUPINFO));
    stinfo.cb = sizeof(STARTUPINFO);
    stinfo.hStdInput = pipes[STDIN_READ_CHILD];
    stinfo.hStdOutput = pipes[STDOUT_WRITE_CHILD];
    stinfo.hStdError = pipes[STDERR_WRITE_CHILD];
    stinfo.dwFlags |= STARTF_USESTDHANDLES;
    size = unicode_convers(command, (char_t *)(commandw + 7), ekUTF8, ekUTF16, (1024 - 7) * sizeof(WCHAR));
    if (size < (1024 - 7) * sizeof(WCHAR))
    {
        BOOL ok = CreateProcess(NULL, commandw, NULL, NULL, TRUE, 0, NULL, NULL, &stinfo, info);
        if (ok == TRUE)
        {
            /* Close the parent copy of child descriptors */
            CloseHandle(pipes[STDIN_READ_CHILD]);
            CloseHandle(pipes[STDOUT_WRITE_CHILD]);
            CloseHandle(pipes[STDERR_WRITE_CHILD]);
            pipes[STDIN_READ_CHILD] = NULL;
            pipes[STDOUT_WRITE_CHILD] = NULL;
            pipes[STDERR_WRITE_CHILD] = NULL;
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    return FALSE;
}

/*---------------------------------------------------------------------------*/

Proc *bproc_exec(const char_t *command, perror_t *error)
{
    HANDLE pipes[6];
    PROCESS_INFORMATION info;

    if (i_pipes(pipes) == FALSE)
    {
        ptr_assign(error, ekPPIPE);
        return NULL;
    }

    if (i_exec(command, pipes, &info) == FALSE)
    {
        i_close_pipes(pipes);
        ptr_assign(error, ekPEXEC);
        return NULL;
    }

    ptr_assign(error, ekPOK);
    return i_create(pipes, &info);
}

/*---------------------------------------------------------------------------*/

void bproc_close(Proc **proc)
{
    cassert_no_null(proc);
    cassert_no_null(*proc);
    cassert_no_null((*proc)->info.hProcess);
    cassert_no_null((*proc)->info.hThread);
    i_close_pipes((*proc)->pipes);
    CloseHandle((*proc)->info.hProcess);
    CloseHandle((*proc)->info.hThread);
    _osbs_proc_dealloc();
    bmem_free((byte_t *)*proc);
    *proc = NULL;
}

/*---------------------------------------------------------------------------*/

bool_t bproc_cancel(Proc *proc)
{
    cassert_no_null(proc);
    if (TerminateProcess(proc->info.hProcess, 0) != 0)
        return TRUE;
    else
        return FALSE;
}

/*---------------------------------------------------------------------------*/

uint32_t bproc_wait(Proc *proc)
{
    DWORD exit_code = 0;
    cassert_no_null(proc);
    WaitForSingleObject(proc->info.hProcess, INFINITE);
    if (GetExitCodeProcess(proc->info.hProcess, &exit_code) != 0)
    {
        cassert(exit_code != STILL_ACTIVE);
        return (uint32_t)exit_code;
    }
    else
    {
        return UINT32_MAX;
    }
}

/*---------------------------------------------------------------------------*/

bool_t bproc_finish(Proc *proc, uint32_t *code)
{
    DWORD exit_code;
    cassert_no_null(proc);
    if (GetExitCodeProcess(proc->info.hProcess, &exit_code) != 0)
    {
        if (exit_code != STILL_ACTIVE)
        {
            ptr_assign(code, (uint32_t)exit_code);
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        cassert(FALSE);
        return TRUE;
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_read_pipe(HANDLE pipe, byte_t *data, const uint32_t size, uint32_t *rsize, perror_t *error)
{
    DWORD lrsize;
    BOOL ok;
    ok = ReadFile(pipe, (LPVOID)data, (DWORD)size, &lrsize, NULL);
    if (ok == TRUE)
    {
        if (lrsize > 0)
        {
            ptr_assign(rsize, (uint32_t)lrsize);
            ptr_assign(error, ekPOK);
            return TRUE;
        }
        else
        {
            cassert(lrsize == 0);
            ptr_assign(rsize, 0);
            ptr_assign(error, ekPOK);
            return FALSE;
        }
    }
    else
    {
        if (GetLastError() == ERROR_BROKEN_PIPE)
        {
            ptr_assign(rsize, 0);
            ptr_assign(error, ekPOK);
        }
        else
        {
            ptr_assign(rsize, 0);
            ptr_assign(error, ekPPIPE);
        }
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t bproc_read(Proc *proc, byte_t *data, const uint32_t size, uint32_t *rsize, perror_t *error)
{
    return i_read_pipe(proc->pipes[STDOUT_READ_PARENT], data, size, rsize, error);
}

/*---------------------------------------------------------------------------*/

bool_t bproc_eread(Proc *proc, byte_t *data, const uint32_t size, uint32_t *rsize, perror_t *error)
{
    return i_read_pipe(proc->pipes[STDERR_READ_PARENT], data, size, rsize, error);
}

/*---------------------------------------------------------------------------*/

bool_t bproc_write(Proc *proc, const byte_t *data, const uint32_t size, uint32_t *wsize, perror_t *error)
{
    DWORD lwsize;
    BOOL ok;
    cassert_no_null(proc);
    ok = WriteFile(proc->pipes[STDIN_WRITE_PARENT], (LPCVOID)data, (DWORD)size, &lwsize, NULL);
    if (ok == TRUE)
    {
        ptr_assign(wsize, (uint32_t)lwsize);
        ptr_assign(error, ekPOK);
        return TRUE;
    }
    else
    {
        ptr_assign(error, ekPOK);
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t bproc_read_close(Proc *proc)
{
    cassert_no_null(proc);
    if (proc->pipes[STDOUT_READ_PARENT] != NULL)
    {
        CloseHandle(proc->pipes[STDOUT_READ_PARENT]);
        proc->pipes[STDOUT_READ_PARENT] = NULL;
        return TRUE;
    }
    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t bproc_eread_close(Proc *proc)
{
    cassert_no_null(proc);
    if (proc->pipes[STDERR_READ_PARENT] != NULL)
    {
        CloseHandle(proc->pipes[STDERR_READ_PARENT]);
        proc->pipes[STDERR_READ_PARENT] = NULL;
        return TRUE;
    }
    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t bproc_write_close(Proc *proc)
{
    cassert_no_null(proc);
    if (proc->pipes[STDIN_WRITE_PARENT] != NULL)
    {
        CloseHandle(proc->pipes[STDIN_WRITE_PARENT]);
        proc->pipes[STDIN_WRITE_PARENT] = NULL;
        return TRUE;
    }
    return FALSE;
}

/*---------------------------------------------------------------------------*/

void bproc_exit(const uint32_t code)
{
    ExitProcess((UINT)code);
}
