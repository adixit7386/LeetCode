<h2><a href="https://leetcode.com/problems/ones-and-zeroes/">474. Ones and Zeroes</a></h2><h3>Medium</h3><hr><div><p>You are given an array of binary strings <code style="">strs</code> and two integers <code style="">m</code> and <code style="">n</code>.</p>

<p>Return <em style="">the size of the largest subset of <code style="">strs</code> such that there are <strong>at most</strong> </em><code style="">m</code><em style=""> </em><code style="">0</code><em style="">'s and </em><code style="">n</code><em style=""> </em><code style="">1</code><em style="">'s in the subset</em>.</p>

<p>A set <code style="">x</code> is a <strong>subset</strong> of a set <code style="">y</code> if all elements of <code style="">x</code> are also elements of <code style="">y</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre style=""><strong>Input:</strong> strs = ["10","0001","111001","1","0"], m = 5, n = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre style=""><strong>Input:</strong> strs = ["10","0","1"], m = 1, n = 1
<strong>Output:</strong> 2
<b>Explanation:</b> The largest subset is {"0", "1"}, so the answer is 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code style="">1 &lt;= strs.length &lt;= 600</code></li>
	<li><code style="">1 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code style="">strs[i]</code> consists only of digits <code style="">'0'</code> and <code style="">'1'</code>.</li>
	<li><code style="">1 &lt;= m, n &lt;= 100</code></li>
</ul>
</div>