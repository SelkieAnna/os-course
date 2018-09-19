#!/bin/bash

(sleep 3s; pkill -f ex2.sh)&
bash ex2.sh&
bash ex2.sh&
