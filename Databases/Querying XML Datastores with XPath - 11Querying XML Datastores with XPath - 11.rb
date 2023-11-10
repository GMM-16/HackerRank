=begin
XPath is a very valuable tool, often used for querying XML databases. XPath queries (or close variants) are also used in the process of Web Scraping while retreiving data from structured XHTML-compliant web pages, specially those with tabulated data.

Provided XML Fragment and Task Description
Assume that you have been provided the fragment of XML, shown below. Your task is to write the XPath selector for listing the titles of the movies which occur at odd positions in the XML, in the same order as which they occur in the given XML (i.e, the first record, third record, etc.).
The Ruby code for handling input, output and document construction has already been provided. You only need to fill up the required blanks as indicated in the template code provided. This challenge is agnostic to language-specific knowledge and you do not require to know ruby - as only the XPath selector needs to be completed by you.

<collection shelf="Classics">
<movie title="The Enemy" shelf="A">
   <type>War, Thriller</type>
   <format>DVD</format>
   <year>2001</year>
   <rating>PG</rating>
   <popularity>10</popularity>
   <description>Talk about a war</description>
</movie>
<movie title="Transformers" shelf="B">
   <type>Science Fiction</type>
   <format>DVD</format>
   <year>1980</year>
   <rating>R</rating>
   <popularity>7</popularity>
   <description>Science Fiction</description>
</movie>
   <movie title="Trigun" shelf="B">
   <type>Action</type>
   <format>DVD</format>
   <episodes>4</episodes>
   <rating>PG</rating>
   <popularity>10</popularity>
   <description>Quite a bit of action!</description>
</movie>
<movie title="Ishtar" shelf="A">
   <type>Comedy</type>
   <format>VHS</format>
   <rating>PG</rating>
   <popularity>2</popularity>
   <description>Boring</description>
</movie>
</collection>
=end

# Standard ruby library for XML parsing
require 'rexml/document'
include REXML

# Enter your code here. Read input from STDIN. Print output to STDOUT
xmlText = "" 

# Read the input XML Fragment
while line = gets()
	xmlText += line
end

doc = Document.new xmlText

# XPath Selector for listing the titles of the movies, in the same order as which they occur in the given XML.
# Fill in the blanks to complete the required XPath selector query
puts doc.elements.each("//movie[position() mod 2 =1]/@title")

# Standard ruby library for XML parsing
require 'rexml/document'
include REXML

# Enter your code here. Read input from STDIN. Print output to STDOUT
xmlText = "" 

# Read the input XML Fragment
while line = gets()
	xmlText += line
end

doc = Document.new xmlText

# XPath Selector for listing the titles of the movies, in the same order as which they occur in the given XML.
# Fill in the blanks to complete the required XPath selector query
puts doc.elements.each("//movie[position() mod 2 =1]/@title")
