SELECT e.unique_id,es.name
FROM EmployeeUNI e
RIGHT JOIN Employees es
ON e.id=es.id;
