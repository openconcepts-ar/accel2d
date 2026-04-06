echo flatpak --command=sh run org.kicad.KiCad

python3 -m kikit.ui export gerber Palelized-4layer.kicad_pcb .
rm -f Palelized-4layer.zip; zip Palelized-4layer.zip Palelized-4layer-* Palelized-4layer.*

