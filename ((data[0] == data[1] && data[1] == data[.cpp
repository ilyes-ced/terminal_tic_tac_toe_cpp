((data[0] == data[1] && data[1] == data[2]) ||
            (data[3] == data[4] && data[4] == data[5]) ||
            (data[6] == data[7] && data[8] == data[9])) || 
            ((data[0] == data[3] && data[3] == data[6]) ||
            (data[3] == data[4] && data[4] == data[5]) ||
            (data[6] == data[7] && data[8] == data[9]))

(
    (data[0] == data[1] && data[1] == data[2])
    ||
    (data[3] == data[4] && data[4] == data[5])
    ||
    (data[6] == data[7] && data[7] == data[8])
)
||
(
    (data[0] == data[3] && data[3] == data[6])
    ||
    (data[1] == data[4] && data[4] == data[7])
    ||
    (data[2] == data[5] && data[5] == data[8])
)
||
(
    (data[0] == data[4] && data[4] == data[8])
    ||
    (data[2] == data[4] && data[4] == data[6])
)