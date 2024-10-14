#!/usr/bin/env node
//@ts-check
'use strict';

const esbuild = require('esbuild');

const isProd = process.env.NODE_ENV === 'production';

esbuild.build({
	platform: 'node',
	entryPoints: ['./src/extension.ts'],
	outdir: './out',
	external: ['vscode'],
	format: 'cjs',
	sourcemap: 'external',
	bundle: true,
	minify: isProd
});