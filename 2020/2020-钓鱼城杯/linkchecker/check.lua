function check0(cipher)
    local tbl = {}
    local sum = 0;
    local k = 220
    for i=1, #cipher do
        local x = string.byte(cipher, i)
        sum = (sum * k + x) % 65537
        tbl[i] = x
    end
--    print(sum)
    if sum == 16047 then
        return libcheck.check1(tbl)
    else
        return 1
    end
end

function check2(cipher)
    local sum = 0;
    local k = 39
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 18580 then
        return libcheck.check3(cipher)
    else
        return 1
    end
end

function check4(cipher)
    local sum = 0;
    local k = 4
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 1520 then
        return libcheck.check5(cipher)
    else
        return 1
    end
end

function check6(cipher)
    local sum = 0;
    local k = 137
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 8828 then
        return libcheck.check7(cipher)
    else
        return 1
    end
end

function check8(cipher)
    local sum = 0;
    local k = 211
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 53648 then
        return libcheck.check9(cipher)
    else
        return 1
    end
end

function check10(cipher)
    local sum = 0;
    local k = 238
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 32347 then
        return libcheck.check11(cipher)
    else
        return 1
    end
end

function check12(cipher)
    local sum = 0;
    local k = 133
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 45053 then
        return libcheck.check13(cipher)
    else
        return 1
    end
end

function check14(cipher)
    local sum = 0;
    local k = 179
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 14264 then
        return libcheck.check15(cipher)
    else
        return 1
    end
end

function check16(cipher)
    local sum = 0;
    local k = 158
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 25879 then
        return libcheck.check17(cipher)
    else
        return 1
    end
end

function check18(cipher)
    local sum = 0;
    local k = 40
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 7217 then
        return libcheck.check19(cipher)
    else
        return 1
    end
end

function check20(cipher)
    local sum = 0;
    local k = 196
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 17903 then
        return libcheck.check21(cipher)
    else
        return 1
    end
end

function check22(cipher)
    local sum = 0;
    local k = 248
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 46799 then
        return libcheck.check23(cipher)
    else
        return 1
    end
end

function check24(cipher)
    local sum = 0;
    local k = 157
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 55445 then
        return libcheck.check25(cipher)
    else
        return 1
    end
end

function check26(cipher)
    local sum = 0;
    local k = 163
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 11450 then
        return libcheck.check27(cipher)
    else
        return 1
    end
end

function check28(cipher)
    local sum = 0;
    local k = 167
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 11581 then
        return libcheck.check29(cipher)
    else
        return 1
    end
end

function check30(cipher)
    local sum = 0;
    local k = 159
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 50599 then
        return libcheck.check31(cipher)
    else
        return 1
    end
end

function check32(cipher)
    local sum = 0;
    local k = 29
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 38986 then
        return libcheck.check33(cipher)
    else
        return 1
    end
end

function check34(cipher)
    local sum = 0;
    local k = 93
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 39558 then
        return libcheck.check35(cipher)
    else
        return 1
    end
end

function check36(cipher)
    local sum = 0;
    local k = 8
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 61814 then
        return libcheck.check37(cipher)
    else
        return 1
    end
end

function check38(cipher)
    local sum = 0;
    local k = 81
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 41021 then
        return libcheck.check39(cipher)
    else
        return 1
    end
end

function check40(cipher)
    local sum = 0;
    local k = 181
    for i=1, #cipher do
        sum = (sum * k + cipher[i]) % 65537
    end
--    print(sum)
    if sum == 19105 then
        return libcheck.check41(cipher)
    else
        return 1
    end
end

