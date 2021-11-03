<h2>1529. Bulb Switcher IV</h2><h3>Medium</h3><hr><div><p>There is a room with <code>n</code> bulbs, numbered from <code>0</code> to <code>n - 1</code>, arranged in a row from left to right. Initially, all the bulbs are <strong>turned off</strong>.</p>

<p>Your task is to obtain the configuration represented by <code>target</code> where <code>target[i]</code> is <code>'1'</code> if the <code>i<sup>th</sup></code> bulb is turned on and is <code>'0'</code> if it is turned off.</p>

<p>You have a switch to flip the state of the bulb, a flip operation is defined as follows:</p>

<ul>
	<li>Choose <strong>any</strong> bulb (index <code>i</code>) of your current configuration.</li>
	<li>Flip each bulb from index <code>i</code> to index <code>n - 1</code>.</li>
</ul>

<p>When any bulb is flipped it means that if it is <code>'0'</code> it changes to <code>'1'</code> and if it is <code>'1'</code> it changes to <code>'0'</code>.</p>

<p>Return <em>the <strong>minimum</strong> number of flips required to form</em> <code>target</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> target = "10111"
<strong>Output:</strong> 3
<strong>Explanation: </strong>Initial configuration "00000".
flip from the third bulb:  "00000" -&gt; "00111"
flip from the first bulb:  "00111" -&gt; "11000"
flip from the second bulb:  "11000" -&gt; "10111"
We need at least 3 flip operations to form target.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> target = "101"
<strong>Output:</strong> 3
<strong>Explanation: </strong>"000" -&gt; "111" -&gt; "100" -&gt; "101".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> target = "00000"
<strong>Output:</strong> 0
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> target = "001011101"
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target.length &lt;= 10<sup>5</sup></code></li>
	<li><code>target[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>
</div>