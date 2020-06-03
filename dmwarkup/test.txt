# "find fluid_transfer/ -type f -print | wc -l"
X=6
for i in $(seq 0 $X); do
    echo "testing problem$i"
    cat "fluid_transfer/problem$i.in" | python3 fluidtra.py > "fluid_transfer/my$i.out" && diff "fluid_transfer/problem$i.out" "fluid_transfer/my$i.out"
done
