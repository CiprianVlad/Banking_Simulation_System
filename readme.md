Owner : Vlad-Ciprian Constandache 

Enhancements : 
Diferenta dintre un cont de savings si unul de de adult e ca nu poti sa faci transfer de bani \
decat dupa 6 iteratii sau mai mult , 1 iteratie insemnand = 1 luna \

Implementez cont de investitii separat de cel de savings \
Key difference between child, student, adult acc va fi comisionul pe care il platesti \

Workflow : 
1.	Add a method in Invest_acc to allow the user to invest a specific amount in a chosen stock.
2.	Check if the account has enough balance.
3.	Calculate how many stocks can be bought with the given amount (using the stock's current index as price).
4.	Decrease the number of stocks for sale in the Stock object.
5.	Deduct the spent amount from the account balance.
6.	Handle cases where the user tries to buy more stocks than available or doesn't have enough money.

