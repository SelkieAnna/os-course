#!/bin/bash

(sleep 3s; pkill -f ex2-1.sh)&
bash ex2-1.sh&
bash ex2-1.sh&
