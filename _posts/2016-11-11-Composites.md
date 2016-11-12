---
layout: post
title: Week Ten&#58; Composites
---

Burlap + Epoxy + Vacuum + Patience = Rough and strong!

### Background

Our assignment this week was to design and fabricate a 3D mold (~ft^2) and produce a fiber composite part in it.

### Design

My final project is not expected to include any Composite parts, so this was a good testing/learning week. I decided to make a cylinder (R=5" Z=2") with a small skull on it. I chose the skull because it is easy to create ("N" in the windings font which is a great source for basic images) and a great way to test the resolution of making composites as they dry - because of the different holes / pieces (eyes, nose, mouth, etc).

Project Files:

[Rhino 3DM file]({{ site.baseurl }}/project_files/CompositeModel.3dm)

[STL file]({{ site.baseurl }}/project_files/CompositeModel.stl)

Modelo:

<div class='modelo-wrapper'> <iframe src="https://beta.modelo.io/embedded/G3yRr6Cidk?viewport=false&autoplay=false" width="640" height="360" frameborder="0" mozallowfullscreen webkitallowfullscreen allowfullscreen ></iframe> <p style="font-size: 13px; font-weight: bold; margin: 10px 10px 10px 0; color: #666666;"> CompositeModel <span style="font-weight: normal;">By</span> Yuval Gonczarowski <a href="http://www.modelo.io?utm_source=embed&utm_medium=embedfooter&utm_campaign=model%20embed%20footer" target="_blank" style="display: inline-block; margin-left: 6px; padding-left: 8px; border-left: 1px solid #e2e2e2; color: #e8776f; cursor: pointer; text-decoration: none;">Modelo »</a> </p> </div>

### Milling

[PartWorks file]({{ site.baseurl }}/project_files/CompositeModel.v3d)

[Rough Cut file]({{ site.baseurl }}/project_files/CompositeModel_Rough.sbp)

[Finish Cut file]({{ site.baseurl }}/project_files/CompositeModel_Finished.sbp)

While technically this design could've been done using fabmodules (it's actually more of a 2.5D design) I decided to go ahead and continue to practice using PartWorks.

The main choices here were:

* Rough Cut using 0.5" mill
* Finish Cut using 0.25" mill

[![_config.yml]({{ site.baseurl }}/images/Composites/ModelInPartWorks.jpg "ModelInPartWorks"){:height="200px"}]({{ site.baseurl }}/images/Composites/ModelInPartWorks.jpg "ModelInPartWorks"){:height="300px"}
[![_config.yml]({{ site.baseurl }}/images/Composites/ModelInPartWorks2.jpg "ModelInPartWorks2"){:height="200px"}]({{ site.baseurl }}/images/Composites/ModelInPartWorks2.jpg "ModelInPartWorks2"){:height="300px"}


Since I used foam for the mold, it was fairly easy and the ShopBot cut it like it was butter. 

* Piece of foam on the ShopBot (glued with hot glue):

[![_config.yml]({{ site.baseurl }}/images/Composites/FoamOnShopBot.jpg "FoamOnShopBot"){:height="200px"}]({{ site.baseurl }}/images/Composites/FoamOnShopBot.jpg "FoamOnShopBot"){:height="300px"}

* Rough Cut in progress (R=0.5"):

[![_config.yml]({{ site.baseurl }}/images/Composites/RoughCut.jpg "RoughCut"){:height="200px"}]({{ site.baseurl }}/images/Composites/RoughCut.jpg "RoughCut"){:height="300px"}

* Model Milled (left a thin layer of 0.2" to make sure I don't mill some wood off the bottom):

[![_config.yml]({{ site.baseurl }}/images/Composites/ModelMilled.jpg "ModelMilled"){:height="200px"}]({{ site.baseurl }}/images/Composites/ModelMilled.jpg "ModelMilled"){:height="300px"}

* The Final Result:

[![_config.yml]({{ site.baseurl }}/images/Composites/FinishedModel.jpg "FinishedModel"){:height="200px"}]({{ site.baseurl }}/images/Composites/FinishedModel.jpg "FinishedModel"){:height="300px"}

* Mistake/Lesson learned: At some point, the spindle caught a small piece of wax/foam on the tip and started scratching deeper; since I wasn't paying attention this happened for some time. Once I noticed it I stopped the cut, cleaned the spindle and resumed cutting. Here we can get a closer look on the mistake (which ended up not being crucial because the resolution was too small to make a difference on the composite):

[![_config.yml]({{ site.baseurl }}/images/Composites/Mistake.jpg "Mistake"){:height="200px"}]({{ site.baseurl }}/images/Composites/Mistake.jpg "Mistake"){:height="300px"}

### Producing the composite

* The first layer is very important - the separation layer. We put that directly on the mold so it will be easily removed. Generally, epoxy doesn't react with nylon / plastic.

[![_config.yml]({{ site.baseurl }}/images/Composites/SeparationLayer.jpg "SeparationLayer"){:height="200px"}]({{ site.baseurl }}/images/Composites/SeparationLayer.jpg "SeparationLayer"){:height="300px"}

* Our adhesive for today is Super Sap 1000 ONF Epoxy. The A:B ratio (Re4sin:Hardener)  is 2:1 as is evident by the different bottle sizes. Each squeeze produces an even quantity. We put 3 squeezes of B and 6 squeezes of A in the mixture.

The Data Sheet can be found [here](https://entropyresins.com/wp-content/uploads/2014/03/TDS_100_1000_v4-TDS-100-1000-System.pdf).

[![_config.yml]({{ site.baseurl }}/images/Composites/EpoxyGlues.jpg "EpoxyGlues"){:height="200px"}]({{ site.baseurl }}/images/Composites/EpoxyGlues.jpg "EpoxyGlues"){:height="300px"}

* Mixing the epoxy for a LONG time is key to success. It takes 4 hours to dry so no real sense in rushing this part. We mixed for a good 10 minutes. This is how it looked when it started:

[![_config.yml]({{ site.baseurl }}/images/Composites/MixingEpoxy.jpg "MixingEpoxy"){:height="200px"}]({{ site.baseurl }}/images/Composites/MixingEpoxy.jpg "MixingEpoxy"){:height="300px"}

* And this is how it looked after mixing well:

[![_config.yml]({{ site.baseurl }}/images/Composites/MixedEpoxy.jpg "MixedEpoxy"){:height="200px"}]({{ site.baseurl }}/images/Composites/MixedEpoxy.jpg "MixedEpoxy"){:height="300px"}

* Our material for today is [Burlap](https://en.wikipedia.org/wiki/Hessian_fabric). Taking a sheet of burlap we put a chunk of epoxy on it, and smear it well and evenly using plastic (think PB&J Sandwich):

[![_config.yml]({{ site.baseurl }}/images/Composites/EpoxyOn.jpg "EpoxyOn"){:height="200px"}]({{ site.baseurl }}/images/Composites/EpoxyOn.jpg "EpoxyOn"){:height="300px"}

[![_config.yml]({{ site.baseurl }}/images/Composites/SmearingEpoxy.jpg "SmearingEpoxy"){:height="200px"}]({{ site.baseurl }}/images/Composites/SmearingEpoxy.jpg "SmearingEpoxy"){:height="300px"}

* We then place the layer with epoxy on the separation layer, and repeat the process several times. Dan, our instructor, recommended 3 sheets for proper strength.

[![_config.yml]({{ site.baseurl }}/images/Composites/LayerWithEpoxyOn.jpg "LayerWithEpoxyOn"){:height="200px"}]({{ site.baseurl }}/images/Composites/LayerWithEpoxyOn.jpg "LayerWithEpoxyOn"){:height="300px"}

[![_config.yml]({{ site.baseurl }}/images/Composites/AllLayersOnEpoxy.jpg "AllLayersOnEpoxy"){:height="200px"}]({{ site.baseurl }}/images/Composites/AllLayersOnEpoxy.jpg "AllLayersOnEpoxy"){:height="300px"}

*Above the epoxy layer we need another separation layer; this time, we poke holes in it (think Matzoh) so that when we place everything in the plastic bag, the epoxy will have where to go:

[![_config.yml]({{ site.baseurl }}/images/Composites/Matzoh.jpg "Matzoh"){:height="200px"}]({{ site.baseurl }}/images/Composites/Matzoh.jpg "Matzoh"){:height="300px"}

[![_config.yml]({{ site.baseurl }}/images/Composites/LayerWithHolesOnTop.jpg "LayerWithHolesOnTop"){:height="200px"}]({{ site.baseurl }}/images/Composites/LayerWithHolesOnTop.jpg "LayerWithHolesOnTop"){:height="300px"}

* And where does the epoxy go? Onto a layer of material with high soaking quality. I think what we used here was felt:

[![_config.yml]({{ site.baseurl }}/images/Composites/FeltSoaker.jpg "FeltSoaker"){:height="200px"}]({{ site.baseurl }}/images/Composites/FeltSoaker.jpg "FeltSoaker"){:height="300px"}

* Next, we place everything in the vacuum bag, but we need some sort of pathway for the air to flow, a "ventilation" system if you will, to the cap. But the cap is made of plastic and is pretty strong, and we don't want that on the burlap so it won't leave a mark. So we create a ventilation path with some more felt and burlap without adhesive:

[![_config.yml]({{ site.baseurl }}/images/Composites/Ventilation.jpg "Ventilation"){:height="200px"}]({{ site.baseurl }}/images/Composites/Ventilation.jpg "Ventilation"){:height="300px"}

* And suck the air out:

[![_config.yml]({{ site.baseurl }}/images/Composites/InVacuumBag.jpg "InVacuumBag"){:height="200px"}]({{ site.baseurl }}/images/Composites/InVacuumBag.jpg "InVacuumBag"){:height="300px"}

### Final product

After vacuuming, I waited about 6 hours (spec sheet says 4; I wanted ice cream), removed everything (fairly easily) from the bag, and voila! Here's what we got:

[![_config.yml]({{ site.baseurl }}/images/Composites/FinalAsCoin.jpg "FinalAsCoin"){:height="200px"}]({{ site.baseurl }}/images/Composites/FinalAsCoin.jpg "FinalAsCoin"){:height="300px"}

[![_config.yml]({{ site.baseurl }}/images/Composites/FinalAsBowl.jpg "FinalAsBowl"){:height="200px"}]({{ site.baseurl }}/images/Composites/FinalAsBowl.jpg "FinalAsBowl"){:height="300px"}

[![_config.yml]({{ site.baseurl }}/images/Composites/FinalAll.jpg "FinalAll"){:height="200px"}]({{ site.baseurl }}/images/Composites/FinalAll.jpg "FinalAll"){:height="300px"}

