import stdlib.StdRandom;
import stdlib.StdOut;
import stdlib.StdStats;
public class PercolationStats
{
	private double[] tries;
	private int t; // number of experiments

	public PercolationStats(int N, int t)
	{
		if(N <=0)
			throw new java.lang.IllegalArgumentException();

		if(t<= 0)
			throw new java.lang.IllegalArgumentException();

		this.t = t;

		tries = new double[t];
		for(int i=0; i<t;i++)
		{
			Percolation percolation = new Percolation(N);

			double threshold = 0;

			while(!percolation.percolates())
			{
				int row = StdRandom.uniform(0,N) +1;
				int column = StdRandom.uniform(0,N) +1;

				if(!percolation.isOpen(row, column))
				{
					threshold++;
					percolation.open(row, column);
				}
			}
			tries[i] = threshold/(N*N);
		}
		}

		public double mean()
		{
			return StdStats.mean(tries);
		}

		public double stddev()
		{
			return StdStats.stddev(tries);
		}

		public double confidenceLow()
		{
			return mean() - 1.96* stddev() /Math.sqrt(t);
		}

		public double confidenceHigh()
		{
			return mean() + 1.96* stddev() /Math.sqrt(t);
		}

		public static void main(String[] args) {
			if(args.length!=2)
				return;

			try
			{
				int N = Integer.parseInt(args[0]);
				int T = Integer.parseInt(args[1]);

				PercolationStats percolationStats = new PercolationStats(N, T);


				StdOut.println("mean                    = "
                    + percolationStats.mean());
            StdOut.println("stddev                  = "
                    + percolationStats.stddev());
            StdOut.println("95% confidence interval = "
                    + percolationStats.confidenceLow() + ", "
                    + percolationStats.confidenceHigh());

			}
			catch (NumberFormatException e)
			{
				StdOut.println("Argument must be an integer");
				return;
			}
			
		
	}
}