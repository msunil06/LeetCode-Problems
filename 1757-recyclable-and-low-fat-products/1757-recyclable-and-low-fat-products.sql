# Write your MySQL query statement below
SELECT product_id 
FROM Products as p
WHERE p.low_fats = 'Y' AND p.recyclable = 'Y'
