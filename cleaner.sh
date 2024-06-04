#!/bin/bash

find /home/rey/Documents/probsol -type f -executable -not -path '*/.git/*' -not -name "*.sh" -delete
