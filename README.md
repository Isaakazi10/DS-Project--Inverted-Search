# Inverted-Search
An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow fast full text searches, at a cost of increased processing when a document is added to the database. The inverted file may be the database file itself, rather than its index. It is the most popular data structure used in document retrieval systems, used on a large scale for example in search engines. The purpose of this project is to implement the inverted search using Hash Algorithms.

An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow fast full text searches, at a cost of increased processing when a document is added to the database. The inverted file may be the database file itself, rather than its index. It is the most popular data structure used in document retrieval systems, used on a large scale for example in search engines.

# Inverted Indices:
The forward index is sorted to transform it to an inverted index. This can be done with the help of the best sorting method. The list is arranged in sorted order of words. This will help to search the words easily in the list and produce the information about the documents in which they are present.

Most computers cannot sort the very large disk files needed to hold the initial word list within a reasonable time frame, and do not have the amount of storage necessary to hold a sorted and unsorted version of that word list, plus the intermediate files involved in the internal sort.

This can be avoided by implementing Hashing or sorted Linked list or Binary Search tree at the time of Indexing. While Indexing, before storing,the words are compared and arranged in the sorting order. This helps to reduce the time complexity in searching for a word through the list. The efficiency can be increased by implementing Hashing, which stores words based on unique indices. So while retrieval of words also the efficiency can be obtained. This index can only determine whether a word exists within a particular document, since it stores no information regarding the frequency and position of the word; it is therefore considered to be a boolean index.

Such an index determines which documents match a query but does not rank matched documents. In some designs the index includes additional information such as the frequency of each word in each document or the positions of a word in each document. Position information enables the search algorithm to identify word proximity to support searching for phrases; frequency can be used to help in ranking the relevance of documents to the query. Such topics are the central research focus of information retrieval.

# Sample Output
![Screenshot from 2023-05-15 17-06-52](https://github.com/Isaakazi10/DS-Project--Inverted-Search/assets/111450259/315b98c3-5ca2-42c8-9adf-f72a8ecaf192)

![Screenshot from 2023-05-15 17-07-06](https://github.com/Isaakazi10/DS-Project--Inverted-Search/assets/111450259/900543a1-7db4-4a9b-8f98-d5aa69ae8684)

![Screenshot from 2023-05-15 17-07-32](https://github.com/Isaakazi10/DS-Project--Inverted-Search/assets/111450259/78e2fca1-3b87-46d1-a11d-a163c56630d0)

![Screenshot from 2023-05-15 17-08-35](https://github.com/Isaakazi10/DS-Project--Inverted-Search/assets/111450259/8c00e20d-ca15-404a-9031-8fe1e9f7ab7c)
