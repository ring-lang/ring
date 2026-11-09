# Building Ring with Clang + LTO + PGO

This folder builds the Ring Compiler/VM for Windows using clang with:

* **LTO** (link-time optimization: `-flto -fuse-ld=lld`), so functions from different source files can be inlined
  into each other;
* **PGO** (profile-guided optimization): a first build records which code paths are hot while running real Ring
  programs, then a second build is optimized using this profile;
* the **standard switch dispatcher** of the VM (no computed goto), or the **computed goto dispatcher** of
  `../vmcgoto` (`buildclang_lto_pgo_cgoto.bat`).

The sources are built as they are; nothing in `language/src` or `language/include` is changed.

## Files

| File | Purpose |
|---|---|
| `buildclang_lto_pgo.bat` | The build: instrumented build, training run, optimized build |
| `buildclang_lto_pgo_cgoto.bat` | The same build, using the computed goto dispatcher (see [Computed goto](#computed-goto)) |
| `pgotrain.ring` | The training run: executes every program of `language/tests/tests.ring` (called by the batch file) |
| `README.md` | This file |

## Requirements

* LLVM for Windows: `clang.exe`, `lld-link.exe` and `llvm-profdata.exe`. 
* The Ring source tree: `language/src`, `language/include` and `language/tests` (the training programs).

## Usage

```
cd ring\language\build\pgo
buildclang_lto_pgo.bat
```

The build takes about 2 minutes; most of it is the training run. Close Ring programs (Ring Notepad, etc.) first: the
batch file replaces `ring.exe`, `ringw.exe` and `ring.dll` in `ring/bin`.

## Output

The same places as `../buildvc.bat`:

| File | Folder |
|---|---|
| `ring.dll`, `ring.lib` (import library) | `ring/lib` |
| `ring.dll`, `ring.exe`, `ringw.exe` | `ring/bin` |

`ring.exe` and `ringw.exe` are linked with an 8 MB stack, like `../buildvc.bat`. The static library
(`ringstatic.lib`) is not built.

Everything is built in a temporary folder `work` first and copied at the end, so a failed build leaves the files in
`ring/bin` and `ring/lib` unchanged. The `work` folder is deleted after a successful build.

## Steps

1. **Instrumented build:** `ring.dll` and `ring.exe` with `-O2 -flto -fuse-ld=lld -fprofile-instr-generate`.
2. **Training run:** `pgotrain.ring` runs every `ring ...` command of `language/tests/tests.ring` (about 920 programs)
   with the instrumented `ring.exe`, in a copy of `language/tests/scripts`. Each process writes its own profile file
   (`LLVM_PROFILE_FILE=work\prof\r_%p.profraw`); programs that read input get `nul` as stdin. Some test programs
   need libraries that are not available in this run; they still give useful profile data.
3. **Merge and optimized build:** `llvm-profdata merge` combines the profiles into `work\ring.profdata`. Then
   `ring.dll`, `ring.exe` and `ringw.exe` are built with `-O2 -flto -fuse-ld=lld -fprofile-instr-use`.

## Options (environment variables)

| Variable | Default | Meaning |
|---|---|---|
| `RINGCLANGPATH` | `c:\pl\llvm\bin` if it exists | Folder of `clang.exe`, `lld-link.exe` and `llvm-profdata.exe` |
| `RINGOUT` | `ring\bin` | Output folder of `ring.dll`, `ring.exe` and `ringw.exe` |
| `RINGLIBOUT` | `ring\lib` | Output folder of `ring.dll` and `ring.lib` |
| `RINGCFLAGS` | `-O2` | Optimization flags |
| `RINGKEEPWORK` | not set | When set, the `work` folder (profile data, training copy) is kept |

The same options apply to `buildclang_lto_pgo_cgoto.bat`.

For example, to build into another folder without touching `ring/bin`:

```
set RINGOUT=c:\temp\ringpgo
set RINGLIBOUT=c:\temp\ringpgo
buildclang_lto_pgo.bat
```

## Computed goto

`buildclang_lto_pgo_cgoto.bat` does the same steps as `buildclang_lto_pgo.bat`, with the computed goto dispatcher
of the VM:

```
cd ring\language\build\pgo
buildclang_lto_pgo_cgoto.bat
```

* `../vmcgoto/vmcgoto.c` (`ring_vm_computedgoto()`) is added to the files of `ring.dll`;
* `-DRING_VM_COMPUTEDGOTO=1` is passed to every clang command
* the temporary folder is `workcgoto` (not `work`), so both builds can be kept with `RINGKEEPWORK`.

The output files and folders are the same as `buildclang_lto_pgo.bat` (it replaces the files in `ring/bin` and
`ring/lib`).