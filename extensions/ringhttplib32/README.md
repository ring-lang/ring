# RingHTTPLib32 Extension

## Introduction

This extension provides support for an old version of the cpp-httplib library (32bit/64bit)

URL: https://github.com/yhirose/cpp-httplib

Newer versions of cpp-httplib doesn't support 32bit 

For using a newer version check ring/extensions/ringhttplib folder

## Install

	ringpm install httplib from ringpackages

## Example

	load "httplib.ring"

	oServer = new Server {

		? "Try localhost:8080/hi"
		route(:Get,"/hi",:mytest)

		? "Listen to port 8080"
		listen("0.0.0.0", 8080)

	}

	func mytest 
		oServer.setContent("Hello World!", "text/plain")

## Samples

URL: https://github.com/ring-lang/ring/tree/master/samples/UsingHTTPLib