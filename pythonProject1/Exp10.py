"""
create a dictionary with a set of books with titles and no of stocks

there are 3 functions
update
delete
add
"""


def insert(dictionary: dict, no: int):
    for i in range(no):
        name_of_book = input("Enter the name of the book\n")
        stock_of_book = int(input("Enter the current stock of the book\n"))
        dictionary[name_of_book] = stock_of_book
        # inserted the name as key and stock as value


def delete(dictionary: dict, book_name: str):
    for i, j in dictionary.items():
        if i == book_name:  # target found
            stock1 = int(input("Enter the how much to remove\n"))
            if stock1 < j:
                dictionary[i] = j - stock1
            else:
                print("Deletion not possible\n")


def update(dictionary: dict, book_name: str):
    for i, j in dictionary.items():
        if i == book_name:  # target found
            stock1 = int(input("Enter the how much to add\n"))
            dictionary[i] = j + stock1


d = {}
number_of_terms = int(input("Enter the number of books to be added\n"))
insert(d, number_of_terms)
print(d)
target = input("Enter the name of the book stocks update cheyann\n")
update(d, target)
print(d)
delete(d, target)
print(d)
