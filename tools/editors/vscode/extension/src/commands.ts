import { window } from 'vscode';
import { execRingInTerminal, execRing2EXEInBg } from './exec';

/**
 * Run the current file.
 */
export async function run(): Promise<void> {
	const editor = window.activeTextEditor;
	if (!editor) {
		window.showErrorMessage('Error');
		return;
	}

	const document = editor.document;
	await document.save();
	const filePath = `"${document.fileName}"`;

	execRingInTerminal([filePath]);
}

/**
 * Run the current file with clock argument.
 */
export async function clock(): Promise<void> {
	const editor = window.activeTextEditor;
	if (!editor) {
		window.showErrorMessage('Error');
		return;
	}

	const document = editor.document;
	await document.save();
	const filePath = `"${document.fileName}"`;

	execRingInTerminal([filePath, '-clock']);
}

/**
 * Create an executable file using Ring2EXE.
 */
export async function ring2exe(): Promise<void> {
	const editor = window.activeTextEditor;
	if (!editor) {
		window.showErrorMessage('Error');
		return;
	}

	const document = editor.document;
	await document.save();
	const filePath = `"${document.fileName}"`;

	execRing2EXEInBg([filePath]);
}

/**
 * Create a static executable file using Ring2EXE.
 */
export async function ring2exe_static(): Promise<void> {
	const editor = window.activeTextEditor;
	if (!editor) {
		window.showErrorMessage('Error');
		return;
	}

	const document = editor.document;
	await document.save();
	const filePath = `"${document.fileName}"`;

	execRing2EXEInBg([filePath, "-static"]);
}

/**
 * Distribute a dynamic executable file using Ring2EXE.
 */
export async function ring2exe_dist(): Promise<void> {
	const editor = window.activeTextEditor;
	if (!editor) {
		window.showErrorMessage('Error');
		return;
	}

	const document = editor.document;
	await document.save();
	const filePath = `"${document.fileName}"`;

	execRing2EXEInBg([filePath, "-dist"]);
}

/**
 * Distribute an executable file using Ring2EXE with all runtime.
 */
export async function ring2exe_dist_allruntime(): Promise<void> {
	const editor = window.activeTextEditor;
	if (!editor) {
		window.showErrorMessage('Error');
		return;
	}

	const document = editor.document;
	await document.save();
	const filePath = `"${document.fileName}"`;

	execRing2EXEInBg([filePath, "-dist -allruntime"]);
}

