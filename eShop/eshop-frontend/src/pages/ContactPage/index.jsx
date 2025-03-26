import Navbar from "../../components/Navbar";

const ContactPage = () => {
    return (
        <>
        <Navbar />
        <div className="container mt-5">
            <h2 className="text-center mb-4">Contact Us</h2>
            <div className="row justify-content-center">
                <div className="col-md-6">
                    <form>
                        <div className="mb-3">
                            <label className="form-label">Name</label>
                            <input type="text" className="form-control" placeholder="Enter your name" required />
                        </div>
                        <div className="mb-3">
                            <label className="form-label">Email</label>
                            <input type="email" className="form-control" placeholder="Enter your email" required />
                        </div>
                        <div className="mb-3">
                            <label className="form-label">Message</label>
                            <textarea className="form-control" rows="4" placeholder="Your message..." required></textarea>
                        </div>
                        <button type="submit" className="btn btn-primary w-100">Send Message</button>
                    </form>
                </div>
            </div>
        </div>
        </>
    );
}

export default ContactPage;