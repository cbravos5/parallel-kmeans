#!/bin/bash
export OMP_NUM_THREADS=1
for i in {1..20}
do
    echo "Executing $i th time"
    ./kmeans_p < 10x2M.txt | grep "time" | awk '{print $NF}' >> seq_time.txt
done
