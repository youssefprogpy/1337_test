#!/bin/bash
groups $FT_USER |sed 's/^[^:]*: //' | tr ' '  ',' 
