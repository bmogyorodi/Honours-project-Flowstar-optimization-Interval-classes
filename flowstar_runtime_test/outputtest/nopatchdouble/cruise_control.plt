set terminal postscript enhanced color
set output './images/cruise_control.eps'
set style line 1 linecolor rgb "blue"
set autoscale
unset label
set xtic auto
set ytic auto
set xlabel "v"
set ylabel "x"
plot '-' notitle with lines ls 1
e
