maps=$(ls maps)

for map in $maps
do
	echo "Testing $map"
	valgrind --leak-check=full ./CUB3D maps/$map
	echo ""
done
