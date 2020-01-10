#!/usr/bin/env bash

pandoc --pdf-engine=xelatex description.md -o description.pdf -V geometry:"top=1.5cm, bottom=1.5cm, left=1.5cm, right=1.5cm"
