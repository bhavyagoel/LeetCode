<h2>1513. Number of Substrings With Only 1s</h2><h3>Medium</h3><hr><div><p>Given a binary string&nbsp;<code>s</code>&nbsp;(a string consisting only of '0' and '1's).</p>

<p>Return the number of substrings with all characters 1's.</p>

<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo&nbsp;10^9 + 7.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "0110111"
<strong>Output:</strong> 9
<strong>Explanation: </strong>There are 9 substring in total with only 1's characters.
"1" -&gt; 5 times.
"11" -&gt; 3 times.
"111" -&gt; 1 time.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "101"
<strong>Output:</strong> 2
<strong>Explanation: </strong>Substring "1" is shown 2 times in s.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "111111"
<strong>Output:</strong> 21
<strong>Explanation: </strong>Each substring contains only 1's characters.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "000"
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>s[i] == '0'</code> or <code>s[i] == '1'</code></li>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
</ul></div>