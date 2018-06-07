#つかいかた
#書き込みたいファイルのPATHの変換やってないのでディレクトリ指定があると駄目かも
#sh avrdude.sh 書き込みたいファイル.hex
#ここにbin/avrdude.exeとetc/avrdude.confのあるディレクトリをLinuxの形式で書く
AVRDIR="/mnt/c/tools/arduino/hardware/tools/avr/"


WINDIR=$(echo ${AVRDIR}|sed -e 's/\/mnt\/c\//C:\\/'|sed -e 's/\//\\/g')
MODECMD='/mnt/c/Windows/System32/mode.com'

COMPORT1=$(${MODECMD}|grep -o 'COM[0-9]*')
COMPORT2=""
while [ "$COMPORT2" = "" ];do
 sleep 0.5
 printf "."
 COMPORT2=$(${MODECMD}|grep -v $COMPORT1|grep -o 'COM[0-9]*')
done
echo $COMPORT2

${AVRDIR}bin/avrdude.exe -C ${WINDIR}\etc\\avrdude.conf -c avr109 -p m32u4 -P ${COMPORT2} -U flash:w:$*
