
思考过程： 第一反应是dp,因为和状态有关，但是从这个角度往后想发现怎么样都可能需要O(n^2)级别的算法，而我们需要一个O(nlogn)的算法，这样想一想就想到了排序算法的分治法，而分治法中有一个很经典的推广就是求逆序对的个数，这里发现其实我们要求的也是每个位置各自的逆序对的个数.....两个题目等价罢了，唉

----------

这里在实现上有个需要注意的地方，我在第一个版本中main.cpp中，计算逆序对个数的时候，用到了这样一段
	
	if (nums[x1] <= nums[x2]){	
	    c.push_back(nums[x1]);
	    d.push_back(index[x1]);
	    x1++;
	}else{
	    c.push_back(nums[x2]);
	    d.push_back(index[x2]);
	    // key point here. But not a good solution
	    for (int i=x1; i<=mid; i++)
	    result[index[i]]++;
	    x2++;
	}
这里的思路是，如果nums[x1] > nums[x2], 那么x1到mid每一个数都比nums[x2]大，这样需要再次循环一遍，速度明显变慢

因此第二个版本变成这样:

	if (nums[x1] <= nums[x2]){
        c.push_back(nums[x1]);
        d.push_back(index[x1]);
        // difference
        result[index[x1]]+=(x2-mid-1);
        x1++;
    }else{
        c.push_back(nums[x2]);
        d.push_back(index[x2]);
        //for (int i=x1; i<=mid; i++)
            //result[index[i]]++;
        x2++;
    }
这里如果nums[x1] <= nums[x2]，那么nums[x1]就比已经插入的mid+1 ~ x2-1的所有数都大，这样就不用循环了，在第二个版本中还需要同时更新后面的一小部分，思路相同。