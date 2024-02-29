# Write your MySQL query statement below

Select Person.firstName, Person.lastname, Address.city, Address.state from Person left join Address on Person.personId = Address.personId;