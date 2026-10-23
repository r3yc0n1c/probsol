#!/bin/bash

find . -type f -not -path '*/.git/*' \( -name "*.exe" -o -name "a.out" -o \( ! -name "*.*" -executable ! -name "LICENSE" ! -name "README" \) \) -delete
