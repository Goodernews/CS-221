This is the read me for this homework assignment!!!

Sure will be fun when I push this to github and brag about how I made it with VIM.

Without further adieu, here is a table of the various outputs of the function.


|Inputted Gridpoints|Total Points|Points in Circle| Estimate of Pi| Time to calculate| Time with `constexpr`|
|------------------:|-----------:|:--------------:|---------------|------------------|----------------------|
|10                 |100         |74              |2.96           |0.023 ms          |0.029 ms
|100                |10,000      |7,790           |3.116          |0.035 ms          |0.119 ms
|1,000              |1,000,000   |784,790         |3.13916        |0.103 ms          |0.106 ms
|10,000             |100,000,000 |78,534,000      |3.14136        |0.629 ms          |1.177 ms


# Runtime complexity

I used a less complex function that requires only O(n-2) complexity.

The simplest way is to take the euclidian distance of every point, but this has a complexity of O(n^2), so I avoided it. A similar idea based off of this would be to break any thime no longer within (or out of) radius one.

After a discussion with Evan, we came up with a method that only needed N complexity. It works in two steps: 
1. Calculate the x coordinate given a y coordinate: sqrt(1-y^2)=x
2. Find how many grid points lie within the given step: floor(x/(1/npoints))+1 (cieling could be used, but it helps for situations such as when y=0)

The additional two steps of saving come from the fact that there is no calculation needed for y=0 or y=npoint as they will be npoints and one respectively. This means that runtime is reduced to O(n-2)

# Adding on `constexpr`

What changed, I defined the values of variables earlier on, and I was lazy and made it so x is always reassigning itself.  
As a result, the function got slower. Less temporary memory was called upon. 
