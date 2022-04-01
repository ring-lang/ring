# RingHTTPLib Extension

## Introduction

This extension provides support for the httplib library

URL: https://github.com/yhirose/cpp-httplib

## Install

	ringpm install httplib from ringpackages

## Example

	load "httplib.ring"

	? "Start the server..."
	oServer = new Server 

	? "Try localhost:8080/hi"
	oServer.route(:Get,"/hi",:mytest)

	? "Listen to port 8080"
	oServer.listen("0.0.0.0", 8080)

	func mytest 
		oServer.setContent("Hello World!", "text/plain")

## Samples

URL: https://github.com/ring-lang/ring/tree/master/samples/UsingHTTPLib