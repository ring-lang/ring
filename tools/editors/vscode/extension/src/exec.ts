import { window, Terminal } from 'vscode';
import { getRing2EXECommand, getRingExecCommand } from './utils';
import cp from 'child_process';

let ringRunTerm: Terminal | null = null;

/**
 * Execute Ring in the terminal.
 */
export function execRingInTerminal(args: string[]): void {
	const ring_exec = getRingExecCommand();
	const cmd = `${ring_exec} ${args.join(' ')}`;

	if (!ringRunTerm) ringRunTerm = window.createTerminal('Ring');

	ringRunTerm.show();
	ringRunTerm.sendText(cmd);
}

/**		
 * Execute Ring2EXE in the background.
 */
export function execRing2EXEInBg(args: string[]): void {
	const ring2exe_exec = getRing2EXECommand();
	const cmd = `${ring2exe_exec} ${args.join(' ')}`;

	cp.exec(cmd);
}