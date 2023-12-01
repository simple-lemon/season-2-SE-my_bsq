# season-2-SE-my_bsq
<div class="card-block">
<div class="row">
<div class="col tab-content">
<div class="tab-pane active show" id="subject" role="tabpanel">
<div class="row">
<div class="col-md-12 col-xl-12">
<div class="markdown-body">
<p class="text-muted m-b-15">
</p><h1>My Bsq</h1>
<p>Remember to git add &amp;&amp; git commit &amp;&amp; git push each exercise!</p>
<p>We will execute your function with our test(s), please DO NOT PROVIDE ANY TEST(S) in your file</p>
<p>For each exercise, you will have to create a folder and in this folder, you will have additional files that contain your work. Folder names are provided at the beginning of each exercise under <code>submit directory</code> and specific file names for each exercise are also provided at the beginning of each exercise under <code>submit file(s)</code>.</p>
<hr>
<table>
<thead>
<tr>
<th>My Bsq</th>
<th></th>
</tr>
</thead>
<tbody>
<tr>
<td>Submit directory</td>
<td>.</td>
</tr>
<tr>
<td>Submit files</td>
<td>Makefile - *.c - *.h</td>
</tr>
</tbody>
</table>
<h3>Description</h3>
<h1>Command Name</h1>
<p>Write a programm called <code>my_bsq</code>. Following the specifications of this man page.</p>
<h2>Description</h2>
<p>my_bsq -- finds and prints the biggest square in a map</p>
<h2>SYNOPSIS</h2>
<p>my_bsq [file.txt]</p>
<h2>DESCRIPTION</h2>
<p>This is an algorithm project!! Make it fast or low memory usage or both!</p>
<p>You must find the largest possible square on a board while avoiding obstacles. The board is represented by a file passed as the program’s argument, respecting those constraints:</p>
<p>• Its first line contains the number of lines on the board (and only that),
• <code>.</code> (representing an empty place) and "o" (representing an obstacle) are the only two allowed characters for the other lines
• All of the lines will be the same length (except the first one)
• There will always be at least one line
• Each line is terminated by <code>\n</code>.</p>
<p>You program must print the board, with some "." replaced by "x" to represent the largest square you found.</p>
<h2>Example 00</h2>
<p>input:</p>
<pre class=" language-plain"><code class=" language-plain">5
.....
.o..o
.....
.o...
o...o
</code></pre>
<p>output:</p>
<pre class=" language-plain"><code class=" language-plain">.....
.oxxo
..xx.
.o...
o...o
</code></pre>
<h2>Example 01</h2>
<pre class=" language-plain"><code class=" language-plain">$&gt;./my_bsq map10x10
..xx.
.oxxo
.....
.o...
o...o
$&gt;
</code></pre>
<h2>Requirements</h2>
<ul>
<li>Your code must be compiled with the flags <strong>-Wall -Wextra -Werror</strong>.</li>
</ul>
<h2>Hint(s)</h2>
<ul>
<li>Watch out for <strong>memory leaks</strong> !</li>
<li>You can test your code against memory errors by compiling with the debugging flags <strong>-g3 -fsanitize=address</strong>
</li>
</ul>
<h2>Technical specification</h2>
<ol>
<li>you must create a Makefile, and the ouput is the command itself</li>
<li>You can use:</li>
</ol>
<ul>
<li>malloc(3)</li>
<li>free(3)</li>
<li>open(2)</li>
<li>read(2)</li>
<li>close(2)</li>
<li>printf(3)</li>
<li>write(2)</li>
</ul>
<ol start="3">
<li>You can NOT use:</li>
</ol>
<ul>
<li>Any functions / syscalls which does not appear in the previous list</li>
<li>Yes, it includes <strong>exit</strong>
</li>
<li>Multiline macros are forbidden</li>
<li>Include another .c is forbidden</li>
<li>Macros with logic (while/if/variables/...) are forbidden</li>
</ul>
<p>We are looking for speed, memory optimisation and code architecture.
<a href="https://steemit.com/epitech/@henaff/epitech-bsq-project" target="_blank">Dynamic programming</a>
<a href="https://chunminchang.github.io/blog/post/how-to-simulate-a-c-class-in-c" target="_blank">OOP in C?</a></p>
<p>You should try with differents size of map 10x10... 100x100? :-)</p>
<p>To generate map you can use this perl script:</p>
<pre class=" language-plain"><code class=" language-plain">#!/usr/bin/perl -w

if ((scalar @ARGV) != 3)
{
  print "program x y density\n";
  exit;
}

my $x = $ARGV[0];
my $y = $ARGV[1];
my $density = $ARGV[2];
my $i = 0;
my $j = 0;

print $y . "\n";

while ($i &lt; $y)
{
  $j = 0;
  while ($j &lt; $x)
  {
    if (int(rand($y)*2) &lt; $density)
    {
      print "o";
    }
    else
    {
      print ".";
    }
    $j++;
  }
  print "\n";
  $i++;
}
</code></pre>

<p></p>
</div>

</div>
</div>
</div>
<div class="tab-pane" id="resources" role="tabpanel">
<div class="row">
<div class="col-xl-12">
<div class="row text-center">
<div class="col">
<a target="_blank" href="https://www.geeksforgeeks.org/introduction-of-theory-of-computation/">https://www.geeksforgeeks.org/introduction-of-theory-of-computation/</a>
</div>
</div>
<hr>
<div class="row text-center">
<div class="col">
<a target="_blank" href="https://en.wikipedia.org/wiki/Theory_of_computation">https://en.wikipedia.org/wiki/Theory_of_computation</a>
</div>
</div>
<hr>
<div class="row text-center">
<div class="col">
<a target="_blank" href="https://steemit.com/epitech/@henaff/epitech-bsq-project">https://steemit.com/epitech/@henaff/epitech-bsq-project</a>
</div>
</div>

</div>
</div>
</div>
</div>
</div>
</div>
