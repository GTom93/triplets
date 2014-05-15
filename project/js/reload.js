window.onload = setupRefresh;

function setupRefresh() {
  setTimeout("refreshPage();", 1000);
}
function refreshPage() {
   window.location = location.href;
}