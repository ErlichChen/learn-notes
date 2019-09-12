# PagerAdapter

# FragmentPagerAdapter

The version of the pager is best for use when there are a handful of typically more static fragments to be paged through, such as a set of tabs.
The fragment of each page the user visits will be kept in memory, though its view hierarchy may be destroyed when not visible.
This can result in using a significant amount of memory since fragment instances can hold on to an arbitrary amount of state.
For larger sets of pages, consider FragmentStatePagerAdapter.

# FragementStatePagerAdapter

This version of the pager is more useful when there are a large numbers of pages, working more like a list view.
When pages are not visible to the user, their entire fragment may be destroyed, only keeping the saved state of that fragment.
This allows the pager to hold on to much less memory associated with each visited page as compared to FragmentPagerAdapter at the cost of potentially more overhead when switching between pages.

Like the docs say, think about it this way.
If you were to do an application like a book reader, you will not want to load all the fragments into memory at once.
You would like to load and destroy Fragments as the user reads. In this case you will use FragmentStatePagerAdapter.
If you are just displaying 3 "tabs" that do not contain a lot of heavy data (like Bitmaps), then FragmentPagerAdapter might suit you well.
Also, keep in mind that ViewPager by default will load 3 fragments into memory.
The first Adapter you mention might destroy View hierarchy and reload it when needed, the second Adapter only saves the state of the Fragment and completely destroys it, if the user then comes back to that page, the state is retrieved.