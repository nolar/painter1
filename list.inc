const
  PicturesCount=27;
  PicturesDefault=PicturesCount;
  PicturesName:array[1..PicturesCount]of string=
    (f1c,f2c,f3c,f4c,f5c,f6c,f7c,f8c,f9c,f10c,f11c,f12c,f13c,f14c,f15c,f16c,f17c,f18c,f19c,f20c,f21c,f22c,f23c,f24c,f25c,f26c,f27c);
  PicturesSymmetry:array[1..PicturesCount]of TSymmetry=
    (f1s,f2s,f3s,f4s,f5s,f6s,f7s,f8s,f9s,f10s,f11s,f12s,f13s,f14s,f15s,f16s,f17s,f18s,f19s,f20s,f21s,f22s,f23s,f24s,f25s,f26s,f27s);
  PicturesBorder:array[1..PicturesCount]of TBorderAction=
    (f1b,f2b,f3b,f4b,f5b,f6b,f7b,f8b,f9b,f10b,f11b,f12b,f13b,f14b,f15b,f16b,f17b,f18b,f19b,f20b,f21b,f22b,f23b,f24b,f25b,f26b,f27b);
  PicturesCalculate:array[1..PicturesCount]of TCalculateProc=
    (f1p,f2p,f3p,f4p,f5p,f6p,f7p,f8p,f9p,f10p,f11p,f12p,f13p,f14p,f15p,f16p,f17p,f18p,f19p,f20p,f21p,f22p,f23p,f24p,f25p,f26p,f27p);
