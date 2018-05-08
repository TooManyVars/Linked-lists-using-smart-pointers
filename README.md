# Linked lists using smart pointers

Firstly: what is a linked list? a linked list is a list in which each index has two things: it's data, and the location of the next index.


Creates linked list(s) which uses shared instead of raw pointers in order to minimize the messy memory leaks.

Just a quick note: i've wrapped the code in some Visual studio memory leak detecttion, just to make sure there are none.
I also fix some of the problems seen in other variations of linked lists, such as dangling head / tail nodes, a method to append nodes in bulk,
as well a variety of operations to do on the list.

program is also dryer.

It's a work in progress, so the documentation is still untidy; i'll do that toward the end of the project.
