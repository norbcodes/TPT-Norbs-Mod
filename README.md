# Norb's Mod for the Powder Toy

Hello! This is a little mod i'm making for the amazing game [The Powder Toy](https://powdertoy.co.uk/Download.html). This game has been my favorite sandbox simulation game since when I first got
access to a computer, and so I decided
to learn how to mod it. It took a few hours till I had my first
element working (I didn't bother looking for tutorials because
there probably aren't any) and it was... Interesting.

## Plans for the mod

So far for plans regarding elements, I am planning these:

- [x] *Ozone* - Kills virus upon contact. Condenses into Liquid Ozone at -112C and turns into Oxygen when at -100 pressure. And vice versa, oxygen at 100 pressure turns into ozone.

- [ ] *Neptunium* - Super efficient fuel for nuclear reactors. Goes supercritical slower than plutonium while generating much more temparature.

- [ ] *Neon* - Noble gas that glows when sparked or under pressure. Can be painted with decoration color, which also colors photons.

- [ ] *Chloride* - In powdered and solid form, upon contact with water, it turns it into chlorified water which destroy plant.

- [ ] *Accumulator* - Chargeable battery. Charge it through **PSCN**, and when at max energy, will output to **NSCN** only.

- [ ] *Powered Black Hole* - Activate with **PSCN** to make it behave like black hole, disable with **NSCN**.

- [ ] *Powered Toggle Hole* - When activated with **PSCN**, acts like a black hole, when disabled with **NSCN**, behaves like a white hole.

- [ ] *Aluminium* - Brittle metal, worse conductor, but blocks protons and cools down quickly.

- [ ] *Super Acid* - Extremely corrosive liquid, can eat through glass.

- [ ] *Langton's Ant* - Cellular automaton with simple rules. Because why not?

- [ ] *Pressure Pulse Generator* - Generates pressure pulses. Set temparature to what the pressure level should be generated, and set life to frames between pulses.

I also plan on adding a new element property: *Heat capacity*. When an element transfers heat, the other element that is accepting the heat will only take some of the heat. Basically, for element B with a heat capacity of 0.5 (interval [0.0,1.0]), will change its temperature by heat recieved from element A times heat capacity of element B. Sounds good in my head but I gotta think about if it's actually worth adding and if I want to define heat capacities for all the elements lol.

Elements will be done in no particular order and I will add many more other stuff. As with keeping up with game updates, I'll probably catch up only with major updates that add elements.

## Compiling and running

For that you should consult [this page](https://powdertoy.co.uk/Wiki/W/Building_TPT_with_Meson.html). I got it running with minimal issues, but if you do have issues, open up an Issue on this repo and I'll look into it. Of course if an error shows up you should first check out the TPT wiki and all their resources so that you know if it's an issue with my mod or all the other code.

## Pre built binaries / EXE file?

No. I am not a well known and trusted developer, therefore I will not be providing executables because
who would download random EXEs from some random person on the internet? In fact that's why I keep my mod code open here on GitHub, so you can inspect all the code I push and be sure that what you are about compile is safe.

That's all for now. Enjoy or study my mod, I don't care, FOSS rules, peace out
