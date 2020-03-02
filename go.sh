file=`ls -t *.cpp | head -1`
echo "Compiling $file"
if g++ -std=c++11 $file; then
  echo "Compiled Successfully. Now executing a.out"
  ./a.out < 0data.in
fi

