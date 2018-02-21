import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;


public class Percolation
{
private boolean[][] id;
	private int n;
	private WeightedQuickUnionUF uf;
	private WeightedQuickUnionUF isfullUF;
	public Percolation(int n)
	{
		this.n = n;
		id = new boolean[n+1][n+1];
		uf = new WeightedQuickUnionUF(1 + n*n +1);
		isfullUF = new WeightedQuickUnionUF(1 + n*n);

		for(int i =1; i<=n;i++)
		{
			union(0 ,i); //connect all nodes to the first node
			uf.union(n*n - i, n*n+1); //connect the bottom row to the last node

		}
	}

	private void checkbounds(int i, int j)
	{
		if(i<1 || i>n)
			throw new java.lang.IllegalArgumentException();
		if(j<1 || j>n)
			throw new java.lang.IllegalArgumentException();
	}

	private int xyto1D(int i, int j)
	{
		return (i-1)*n +j;
	}

	private void union(int p, int q)
	{
		uf.union(p,q);
		isfullUF.union(p,q);
	}

	public void open(int row, int col)
	{
		checkbounds(row,col);

		if (isOpen(row,col))
			return;

		id[row][col] = true;
		connectTop(row, col);
        connectBottom(row, col);
        connectLeft(row, col);
        connectRight(row, col);

	}

	private void connectRight(int i, int j)
	{
		if(j==n)
			return;
		if (isOpen(i,j-1))
		{
			int index = xyto1D(i,j);
			int  target = xyto1D(i, j-1);
			union(index, target);
		}
	}
	
	private void connectLeft(int i, int j)
	{
		if(j==1)
			return;
		if (isOpen(i,j-1))
		{
			int index = xyto1D(i,j);
			int  target = xyto1D(i, j-1);
			union(index, target);
		}
	}

	private void connectBottom(int i, int j)
	{
		if(i==n)
			return;
		if (isOpen(i+1,j))
		{
			int index = xyto1D(i,j);
			int  target = xyto1D(i+1, j);
			union(index, target);
		}
	}

	private void connectTop(int i, int j)
	{
		if(i==1)
			return;
		if (isOpen(i-1,j))
		{
			int index = xyto1D(i,j);
			int target = xyto1D(i-1, j);
			union(index, target);
		}
	}


	public boolean isOpen(int row, int col)
	{
		checkbounds(row,col);
		return (id[row][col]);
	}

	public boolean isFull(int row, int col)
	{
		if(!isOpen(row,col))
			return false;

		int site = xyto1D(row,col);
		return isfullUF.connected(0, site);
	}
	/*
	public int numberofOpenSites()
	{
		int i =0, j=0, count=0;
		for(i=1;i<=n;i++)
		{
			for(j=1 ; j<=n;j++)
			{
				if(id[i][j]==true)
					count++;
			}
		}

		return count;

	}
	*/
	public boolean percolates()
	{
		if(n==1)
		{
			return isOpen(1,1);
		}

		return uf.connected(0, n*n+1);
	}

}
