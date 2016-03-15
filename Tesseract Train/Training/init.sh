text2image --list_available_fonts --fonts_dir=.
rm font_properties
#<fontname> <italic> <bold> <fixed> <serif> <fraktur>
echo "Arial 0 0 0 0 0" >> font_properties
echo "Arial Bold 0 1 0 0 0" >> font_properties
echo "Arial Bold Italic 1 1 0 0 0" >> font_properties
echo "Arial Heavy 0 0 0 0 0" >> font_properties
echo "Arial Italic 1 0 0 0 0" >> font_properties
echo "Calibri 0 0 0 0 0" >> font_properties
echo "Calibri Bold 0 1 0 0 0" >> font_properties
echo "Calibri Bold Italic 1 1 0 0 0" >> font_properties
echo "Calibri Italic 1 0 0 0 0" >> font_properties
echo "Calibri Light 0 0 1 0 0" >> font_properties
echo "Calibri Light Italic 1 0 1 0 0" >> font_properties
echo "Courier 0 0 0 0 0" >> font_properties
echo "Courier New 0 0 0 0 0" >> font_properties
echo "Courier New Bold 0 1 0 0 0" >> font_properties
echo "Courier New Bold Italic 1 1 0 0 0" >> font_properties
echo "Courier New Italic 1 0 0 0 0" >> font_properties
echo "Times new Roman, 0 0 0 1 0" >> font_properties
echo "Times New Roman, Bold 0 1 0 1 0" >> font_properties
echo "Times New Roman, Bold Italic 1 1 0 1 0" >> font_properties
echo "Times New Roman, Italic 1 0 0 1 0" >> font_properties
