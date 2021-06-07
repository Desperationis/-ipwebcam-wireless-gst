if ! [[ -d build ]]
then
	mkdir build
fi

cd build

cmake ..

if ! [[ -e compile_commands.json ]]
then
	cmake ..
fi

make

echo "Compiling done!"
