
using System;
using System.Collections.Generic;
using System.Collections;
public class Solution
{
	private int n;
	private int k;
	private IList<IList<int>> ret;
	public void CombineHelper(int start, IList<int> currComb)
	{
		if (currComb.Count == this.k)
		{
			ret.Add(new List<int>(currComb));
			return;
		}
		for(int i = start; i <= n; i++)
		{
			currComb.Add(i);
			CombineHelper(i+1, currComb);
			currComb.Remove(currComb.Count-1);
		}
	}

	public IList<IList<int>> Combine(int n, int k)
	{
		ret = new List<IList<int>>();
		this.n = n;
		this.k = k;
		CombineHelper(1, new List<int>());
		return this.ret;
	}
}