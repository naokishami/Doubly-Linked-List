# Doubly-Linked-List

# Class: Data Structures - Irvine Valley College Fall 2019

Program Specification:
1. Read data for names and weights for 15 people from the console where there is a name on a line followed by a weight on the next line, like in names.txt.
2. Your program will build a list for the data maintained in ascending order based on both name and weight via a doubly linked list.
3. This dll will use one pointer to keep weights in sorted order, and use the other link to keep names on sorted order.
4. You need to build the list as you go maintaining this ordering, so at any time a print method was called it would print the related field in order. (This means nodes are added to the list in sorted order, elements are not added to the list followed by a sort called on the list.)

For example after 3 elements are added for (Name – Weight):
Michael – 275, Tom – 150, Abe – 200.

Output:
Names & weights sorted(ascending) by name. : Abe – 200, Michael – 275, Tom - 150
Names & weights sorted(ascending) by weight. : Tom – 150, Abe – 200, Michael - 275
