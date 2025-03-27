import axios from "axios";

const ApiClient = axios.create({
    baseURL:"http://localhost:8080/api",
    headers: {
        "Content-Type" : "application/json"
    },
});

// retrieve auth token from local storage
function getAuthToken(){
    return localStorage.getItem("token");
}

// request intercepter to include auth token in every request
ApiClient.interceptors.request.use(config => {
    const token = getAuthToken();
    if(token){
        config.headers.Authorization = `Bearer ${token}`;
    }
    return config;
}, error => console.log(error));

export default ApiClient;