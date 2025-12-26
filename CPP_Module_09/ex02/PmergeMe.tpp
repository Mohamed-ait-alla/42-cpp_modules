// ****************************************************************************** //
//                        file: PmergeMe.tpp                                      //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/26 11:30 by mait-all                   //
//                        Updated: 2025/12/26 17:54 by mait-all                   //
// ****************************************************************************** //

#ifndef PMERGEME_TPP
# define PMERGEME_TPP
# include "PmergeMe.hpp"

template <typename T>
void	restoreB(T& a, T& b, T& restoredB)
{
	int	n = a.size();

	for (int i = 0; i < n; i++)
	{
		int idx = a[i].getIndex();
		restoredB.push_back(b[idx]);
	}

	if (static_cast<int>(b.size()) > n)
		restoredB.push_back(b[n]);	
}

template <typename T>
void	makePairs(T& nums, T& a, T& b)
{
	int	n = nums.size() - 1;

	for (int i = 0; i < n; i += 2)
	{
		if (nums[i] < nums[i + 1])
		{
			nums[i + 1].saveIndex(a.size());
			a.push_back(nums[i + 1]);
			b.push_back(nums[i]);
		}
		else
		{
			nums[i].saveIndex(a.size());
			a.push_back(nums[i]);
			b.push_back(nums[i + 1]);
		}
	}
	
	// if there is an odd number add it to b
	if ((n + 1) % 2 != 0)
		b.push_back(nums[n]);
}

template <typename T>
void	mergeInsert(T& nums)
{
	if (nums.size() < 2)
		return ;

	T	a;
	T	b;
	T	restoredB;

	makePairs(nums, a, b);

	mergeInsert(a);

	restoreB(a, b, restoredB);

	nums.clear();
	nums.push_back(restoredB[0]);

	int 		previousJNb = 0;
	int			u = 0;
	const int	bN = restoredB.size();
	const int	aN = a.size();

	for(int k = 2; previousJNb < bN - 1; k++)
	{
		int	currentJNb = t_sequence(k);
		int	m = std::min(currentJNb + 1, bN);

		while (u < currentJNb && u < aN)
		{
			nums.push_back(a[u++]);
		}

		for(int i = m, j = 0; i > previousJNb + 1; i--, j++)
		{
			typename T::iterator it = std::lower_bound(nums.begin(), nums.end() - j, restoredB[i - 1]);
			nums.insert(it, restoredB[i - 1]);
		}
		previousJNb = currentJNb;
	}

	// insert any remaining elements from a
	for(; u < aN; u++)
	{
		nums.push_back(a[u]);
	}
}

template <typename T>
double	sortAndTime(T& _Seq)
{
	double start = getCurrentTimeMicroseconds();
	mergeInsert(_Seq);
	double end = getCurrentTimeMicroseconds();
	return (end - start);
}

template <typename T>
void	isSorted(T _Seq)
{
	for (size_t i = 1; i < _Seq.size(); i++)
	{
		if (_Seq[i] < _Seq[i - 1])
			throw std::runtime_error("Warning: Sequence not properly sorted!");
	}
}

#endif /* __PMERGEME_TPP__ */