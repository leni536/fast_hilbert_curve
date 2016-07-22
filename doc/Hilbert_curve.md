# What is a Hilbert curve?

Rather than rigorously defining the Hilbert curve I choose to show how to draw the Hilbert curve by example. To be a little more precise I describe a Hilbert curve for every natural number (starting from 0).

Some (not defining) properties of the Hilbert curve:

* The nth Hilbert curve is defined on a 2<sup>n</sup>✕2<sup>n</sup> grid.
* The nth Hilbert curve is an ordered series of 2<sup>2n</sup> points, each points on the grid is visited exactly once.
* Subsequent points are neighbours.
* Each Hilbert curve's first point is the very bottom left point of the grid, the last point is the very bottom right point of the grid.

For example the 2nd iteration of the Hilbert curve looks like this:

![2nd iteration][2nd iter]

By following the lines (starting from the bottom left corner) one can see the order of the grid points visited. But at this point we don't really know, how the 2nd iteration looks like, I just pulled that out from thin air. But we know the three properties above, I represent these buy this "black box":

![2nd iteration black box][2nd box]

I use an arrow, so it shows which is the first and the last point of the curve. Similarly the "black box" of the 3rd Hilbert curve looks like this:

![3rd iteration black box][3rd box]

Now I show how to draw the 3rd Hilbert curve assuming we already know how to draw the 2nd one. It basically looks like this:

![3rd iteration from 2nd][3 from 2]

The idea is that we draw a Hilbert curve in each quadrant in a way that the 1st quadrant's last point and the 2nd quadrant's first point are next to each other. Note that we have to reflect the 2nd iteration for the 1st and 4th quadrant. For the 1st quadrant the axis of reflection is the bottom left → top right diagonal, for the 4th quadrant it's the other diagonal. Why reflection and not rotation? Because the direction of the blue arrows matter.

Now what it looks like if we substitute the 2nd iteration that I showed you before:

![2nd iteration substituted to 3rd receipt][3 substituted] → ![3rd iteration][3rd iter]

Now instead of pulling the 2nd curve from thin air we can actually do the same for the 2nd curve, the 1st curve, the 0th curve... Oh the 0th curve. It's defined on a 2<sup>0</sup>✕2<sup>0</sup> (1✕1) grid, it's a single point, one can start from there.

[2nd iter]: https://cdn.rawgit.com/leni536/fast_hilbert_curve/master/doc/2nd_iter.svg
[2nd box]:  https://cdn.rawgit.com/leni536/fast_hilbert_curve/master/doc/2nd_iter_box.svg
[3rd box]:  https://cdn.rawgit.com/leni536/fast_hilbert_curve/master/doc/3rd_iter_box.svg
[3 from 2]: https://cdn.rawgit.com/leni536/fast_hilbert_curve/master/doc/3rd_iter_from_2nd.svg
[3 substituted]: https://cdn.rawgit.com/leni536/fast_hilbert_curve/master/doc/3rd_iter_from_2nd_substituted.svg
[3rd iter]: https://cdn.rawgit.com/leni536/fast_hilbert_curve/master/doc/3rd_iter.svg
