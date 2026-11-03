OPENSCAD ?= openscad
COLORSCAD ?= colorscad
BLENDER  ?= blender
PYTHON ?= python3

DEFAULT_SIZE ?= 156

SOURCES := display_model.py display_bezel.py display_bezel_display.py

SOURCES_SCAD 			:= $(SOURCES:.py=.scad)
SOURCES_SCAD_BACK		:= $(SOURCES_SCAD:.scad=_back.scad)
STL_FILES				:= $(SOURCES_SCAD:.scad=.stl)
SCAD_PNG_FILES			:= $(addsuffix _$(DEFAULT_SIZE).png,$(basename $(SOURCES_SCAD) $(SOURCES_SCAD_BACK)))
BLENDER_JPG_FILES		:= $(addsuffix _$(DEFAULT_SIZE).jpg,$(basename $(SOURCES_SCAD) $(SOURCES_SCAD_BACK)))


.PHONY: all scad stl 3mf amf glb render blender doc clean

all: stl render #blender

scad: $(SOURCES_SCAD)
scad_back: scad $(SOURCES_SCAD_BACK)
stl: scad $(STL_FILES)
render: scad scad_back $(SCAD_PNG_FILES)
blender: scad scad_back $(BLENDER_JPG_FILES)

%.scad: %.py
	$(PYTHON) $< $@ $(DEFAULT_SIZE)

%_back.scad: %.scad
	@echo "module rotated_model() {" > $@
	@cat $< >> $@
	@echo "}" >> $@
	@echo "rotate([0,180,0]) rotated_model();" >> $@
	
%.stl: %.scad
	$(OPENSCAD) --render -o $@ $<

%.amf: %.scad
	$(OPENSCAD) -o $@ $<
	
%_$(DEFAULT_SIZE).png: %.scad
	$(OPENSCAD) --imgsize=1920,1080 --camera=0,0,0,55,0,25,800 --autocenter -o $@ $< #or --viewall

%_$(DEFAULT_SIZE).jpg: %.scad render_scad.py
	#$(COLORSCAD) -i $< -f -o $<.amf
	#$(PYTHON) amf_to_obj.py $<.amf $<.obj
	#$(BLENDER) -b --factory-startup -P render_colored.py -- $<.obj $@
	$(PYTHON) render_scad.py $< $@

doc:
	cp -v $(SCAD_PNG_FILES) $(BLENDER_JPG_FILES) ../doc

clean:
	rm -f $(SOURCES_SCAD) $(SOURCES_SCAD_BACK) $(STL_FILES) $(3MF_FILES) $(AMF_FILES) $(GLB_FILES)  $(SCAD_PNG_FILES) $(SCAD_PNG_BACK_FILES) $(BLENDER_JPG_FILES)

