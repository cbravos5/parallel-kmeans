#!/bin/bash
export OMP_NUM_THREADS=1
echo "TESTE 1 CPU" >> 1core.txt
echo "--------------2M--------------" >> 1core.txt
for i in {1..20}
do
    ./kmeans_p < 10x2M.txt | grep "time" | awk '{print $NF}' >> 1core.txt
done
echo "--------------4M--------------" >> 1core.txt
for i in {1..20}
do
    ./kmeans_p < 10x4M.txt | grep "time" | awk '{print $NF}' >> 1core.txt
done
echo "--------------8M--------------" >> 1core.txt
for i in {1..20}
do
    ./kmeans_p < 10x8M.txt | grep "time" | awk '{print $NF}' >> 1core.txt
done
export OMP_NUM_THREADS=2
echo "TESTE 2 CPU" >> 2core.txt
echo "--------------2M--------------" >> 2core.txt
for i in {1..20}
do
    ./kmeans_p < 10x2M.txt | grep "time" | awk '{print $NF}' >> 2core.txt
done
echo "--------------4M--------------" >> 2core.txt
for i in {1..20}
do
    ./kmeans_p < 10x4M.txt | grep "time" | awk '{print $NF}' >> 2core.txt
done
echo "--------------8M--------------" >> 2core.txt
for i in {1..20}
do
    ./kmeans_p < 10x8M.txt | grep "time" | awk '{print $NF}' >> 2core.txt
done
export OMP_NUM_THREADS=4
echo "TESTE 1 CPU" >> 4core.txt
echo "--------------2M--------------" >> 4core.txt
for i in {1..20}
do
    ./kmeans_p < 10x2M.txt | grep "time" | awk '{print $NF}' >> 4core.txt
done
echo "--------------4M--------------" >> 4core.txt
for i in {1..20}
do
    ./kmeans_p < 10x4M.txt | grep "time" | awk '{print $NF}' >> 4core.txt
done
echo "--------------8M--------------" >> 4core.txt
for i in {1..20}
do
    ./kmeans_p < 10x8M.txt | grep "time" | awk '{print $NF}' >> 4core.txt
done
export OMP_NUM_THREADS=8
echo "TESTE 1 CPU" >> 8core.txt
echo "--------------2M--------------" >> 8core.txt
for i in {1..20}
do
    ./kmeans_p < 10x2M.txt | grep "time" | awk '{print $NF}' >> 8core.txt
done
echo "--------------4M--------------" >> 8core.txt
for i in {1..20}
do
    ./kmeans_p < 10x4M.txt | grep "time" | awk '{print $NF}' >> 8core.txt
done
echo "--------------8M--------------" >> 8core.txt
for i in {1..20}
do
    ./kmeans_p < 10x8M.txt | grep "time" | awk '{print $NF}' >> 8core.txt
done
export OMP_NUM_THREADS=16
echo "TESTE 1 CPU" >> 16core.txt
echo "--------------2M--------------" >> 16core.txt
for i in {1..20}
do
    ./kmeans_p < 10x2M.txt | grep "time" | awk '{print $NF}' >> 16core.txt
done
echo "--------------4M--------------" >> 16core.txt
for i in {1..20}
do
    ./kmeans_p < 10x4M.txt | grep "time" | awk '{print $NF}' >> 16core.txt
done
echo "--------------8M--------------" >> 16core.txt
for i in {1..20}
do
    ./kmeans_p < 10x8M.txt | grep "time" | awk '{print $NF}' >> 16core.txt
done