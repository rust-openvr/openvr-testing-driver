# OpenVR Testing Driver

## What is OpenVR Testing Driver?
Tt's a very basic OpenVR driver implementation. Once it's loaded it will provide an http server with a small JSON REST API.
With this API you can control and load different testing cases as described more in "test_cases/".
Each test case will simulate different hardware features as well as software features.
Once a test case is loaded, your test target application will detect these simulated features and can use them.
The main usage will be for testing openvr applications like bindings for other languages,
or testing your game/application on a CI server that obviously doesn't have any real vr hardware.
Each test case has its own fulfillment rules, the API can be used to get the test results (they're not mandatory though)

## Test cases
Take a look into test_cases folder to see the documentation of each test case.
At the moment if you want to create your own test cases you have to do that in the codebase.
Test cases though are already designed to be independent, and can be easily ported to plugins later.

## Sample usages
- Testing your language binding
- Automatically testing any VR application
- Testing interfacing of OpenVR Application API and OpenVR Driver API
-- Hopefully will detect interface issues as soon as possible, so they can be reported too valve

## Current state of the project
Plannings for the very basic structure and features are done, implementation is currently in work and not usable for now.

## Who is using it?
This driver is part of the development of an OpenVR binding for Rust.