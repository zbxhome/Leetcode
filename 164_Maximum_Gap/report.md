<script type="text/javascript" async src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML"> </script>

## 164 Maximal Gap ##
我采用的方法是基数排序(radix sort)，对于输入大小为n的数组nums,从其二进制表示的最小位到最大位依次做基数排序，所以时间复杂度为O(32*(n+2)) \\( \approx \\)  O(n)

题目的[Solution](https://leetcode.com/articles/maximum-gap/)中提到三种方法:

1. 直接排序，时间复杂度为O(nlogn)
2. 基数排序，但是它用的是十进制数位的基数排序,并且先计算数组中的最大值，以节约比较的次数，其他的基本相同
3. 利用了桶排序的思想，将输入的数组分成n个相同大小的子区间，同时每个区间保存该区间的最大值和最小值，然后进行区间之间的比较即可。前面部分一直在说明的一点时，同一个bucket内的元素不需要再次比较，因为同一个bucket内的最大gap \\( \leq bucketSize \\), 而bucket之间的最大gap\\( \geq bucketSize\\)


----------
其他的一些思考，考虑到基数排序的时间复杂度是O(d*(n+k)),考虑到最大的数是\\( maxVal=2^{31}-1  \\),而\\( d = \lfloor log_{k}(maxVal) \rfloor + 1 \\), 求导尝试解出最优的k与d


