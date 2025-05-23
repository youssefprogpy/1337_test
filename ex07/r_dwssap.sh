FT_LINE1=2
FT_LINE2=5

cat /etc/passwd | \
sed '/^#/d' | \
awk 'NR % 2 == 0' | \
awk -F ':' '{print $1}' | \
rev | \
sort -fnr | \
awk -v FT_LINE1="$FT_LINE1" -v FT_LINE2="$FT_LINE2" 'NR >= FT_LINE1 && NR <= FT_LINE2' | \
tr '\n' ' ' | \
sed 's+ +, +g' | \
sed 's+, $+.+g' | \
tr -d '\n'
