#! /usr/bin/env bash

jq -s '.[0] * .[1]' layout.json macros.json | qmk json2c -
